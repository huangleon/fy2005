#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�������");
    set("long", @LONG
������˵Ҳ�м��������ʷ����˵�ڷ��Ƴ�����֮ǰ�����ˣ��Դ������˵�̳��
��������Խ��Խ�٣�����������ʪ���ƾɲ�����ÿ����紵������ǽ����������
�ƺ����Ͼͻᵹ���������㰸��ֻ��һ֧�����ڷ���ҡҷ����������������ɭɭ��
�ҳ����������ڣ�Ψ�н������һ������ɫ������ȴ��һ����Ⱦ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north"  : __DIR__"didoor", 
      ]));
    set("item_desc", ([
		"kan": "������迪�ں�խ�����ÿ�����һ��ֽ(throw)��\n",
		"����" : "������迪�ں�խ�����ÿ�����һ��ֽ(throw)��\n"
    ]) );
    set("revive_area",1);
    set("objects", ([
		"/obj/specials/ding/ding_fy" : 1,
		__DIR__"npc/monk" : 1,
    ]) );

    set("coor/x",40);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init()
{
    add_action("do_throw", "throw");
}

int do_throw(string arg)
{
    object *inv;
    object me, who;
    object paper;
    object killer;
    string target;
    int targetprice;
    int i;
    if (!arg) return notify_fail("��Ҫ��ʲô�����裿\n");
    if( arg !="youzhi" && arg != "���͵�ֽ")
		return notify_fail("�㲻�ɰ�"+arg+"�������裮\n");
    
    me = this_player();
    who = this_player();
    
    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
    {
		if( (string)(inv[i]->query("name")) == "���͵�ֽ")
		{
	    	paper = inv[i];		
	    	break;
		}
    }
    if( !paper) return notify_fail("��û�����͵�ֽ��\n");
    if( !stringp(paper->query("targetid")))
		return notify_fail("���ֽ��ûд�֡�\n");
        
    if (query("limit")<1)
		return notify_fail("�����������ض���ֽ������������ȥҮ����һ����ɡ�\n");
    
    if (who->is_busy())
		return notify_fail("��������æ��\n");	
    who->perform_busy(2);
    
    target = (string)paper->query("targetid");
    
    killer = new(__DIR__"npc/killer");
    killer->set("possessed",who);
    killer->set_leader(who);
    killer->set("haunttar", target); 
    
    targetprice = (int)paper->query("targetprice");
    destruct(paper);
    
    killer->set("combat_exp", targetprice);		// �� coin Ϊ��λ
    
    targetprice = F_LEVEL->get_level(targetprice) + 20;
    
    killer->set_skill("sword", targetprice);
    killer->set_skill("parry",targetprice);
    killer->set_skill("lefthand-sword", targetprice);
    killer->set_skill("pyrobat-steps",targetprice);
    killer->set_skill("dodge", targetprice);
    "/feature/nada"->reset_npc(killer);
    
    if (killer->query("max_kee")>9000)	killer->set("max_kee",9000);
    if (killer->query("max_sen")>9000)	killer->set("max_sen",9000);
    if (killer->query("max_gin")>9000)	killer->set("max_gin",9000);
    
    killer->full_me();
    message_vision("$N��Цһ������Ŀ���µİ�ֽ�������裮\n",who);
    
    log_file("KILL_LOG",sprintf("(%s)%s����ɱ��ɱ%s\n",
    	ctime(time()),
		who->query("id"),
		killer->query("haunttar")));
    
    add("limit",-1);
    call_out("gothim", 2, who,killer);
    return 1;
}


void gothim(object who, object killer)
{
    if(who && killer) {
	message_vision(BLU"һ�������ӹ���$N�������˸���ս��\n"NOR,who);
	killer->move(this_object());
	if (environment(who) == this_object())
	    message_vision("$N��$n������������ȥ����\n",killer,who);
    }
    if (QUESTS_D->verify_quest(who,"�����Ӱ"))
    	QUESTS_D->special_reward(who,"�����Ӱ");
    
    return;
}

void reset(){
    set("limit",3);
    ::reset();
}
