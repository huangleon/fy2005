// tea_waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
int stone();
void create()
{
        set_name("������", ({ "big fatman","fatman" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һ���װ����ֵİ����ӣ���Ϊ��̫���ˣ�����Ҫ����ϴ�衣\n");
	set("combat_exp", 50000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������ָ���㼥Ц�����㣮������һ��ֻ�������\n",
				"�����Ӻߵ�����Բ֮ҹ���Ͻ�֮�ۣ�Ҷ����Ӯ���ˣ���\n",
        		"������̾�˿�������ʧ�����ˣ����⡣����\n",
				"���������ص��������˵�����ʯ������\n",
		}) );

    	set("inquiry", ([
        	"sword" : (: tell_him :),
        	"����" : (: tell_him:),
        	"stone" : (: stone :),
        	"�����ʯ" : (: stone :),
        	"����":	"���˾��Ƕ��ˣ�����ô֪�����Ķ���֪���һ���û�ҵ���\n",
        	"����":	"action������˫�۾ٹ�ͷ��˵���ҿ��Ե��ݳ��ˣ�\n",	
        ]));

        set("attitude", "friendly");
        set("cps", 25);
        set("cor", 30);
        set("rank_info/respect", "�ָ�");
        set("vendor_goods", ([
                __DIR__"obj/dogmed":10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init(){
	add_action("do_vendor_list", "list");
	add_action("do_look", "look");

}

int stone(){
	object me;
	me = this_player();
	message_vision(YEL"\n$N�ź���˵��������ϧ������Ҳ���Ǻ������ֻ��˵�Ǽ�����������ʯͷ��\n"NOR, this_object());
	message_vision(YEL"������ǰЩ�����и����������С��������������Ҳ����֪��һЩ��Ϣ����\n"NOR,this_object());
	return 1;	
}

int tell_him()
{
    object me;
    me =this_player();
	if (REWARD_D->riddle_check(me,"ʧ���粨")==2
		|| REWARD_D->riddle_check(me,"ʧ���粨")==3 ) {
		tell_object(me,"�����ӵ����ȣ�������Ϊ���˸�����ˣ����϶�������ү����˳�ۣ������ֶ��ˣ�\n");
		REWARD_D->riddle_set(me,"ʧ���粨",3);
		return 1;
	}
	message_vision("������˵��ʲô��������������õúܣ��ò����Ǹ���\n", me);
	return 1;
}

int attack() {
	object opponent;
	
	opponent = select_opponent();
	if(objectp(opponent)) {
		set_temp("last_opponent", opponent);
        if(random(8)) {
		    COMBAT_D->fight(this_object(), opponent);
		} else {
		    message_vision("�����ӳ�$N��ȣ��������㿴��������Ӹ��������������\n", opponent);
		    message_vision("�����Ӻ�������$N��һʱ��$N��ǰ�Ŀռ䱻��������ȫ������\n", opponent);
		    message_vision("�����˲����ˣ����޿�����\n", opponent); 
            message_vision(HIW"\n���䡱��һ���������ӽ��ʵʵ��ײ��$N\n$N��ײ��������ļ�ֽè��\n"NOR, opponent);  
            opponent->unconcious();		    
		    message_vision("\n������Ц������ƾ����������������èҲ�����ұ��ԣ� \n", this_object());
		    this_object()->remove_all_killer();
		}
		return 1;
	} else
		return 0;
}


int do_look(string arg) {
	
	string msg;
	object me, obj;
	me = this_player();
	obj = this_object();
	if (!arg || (arg != ((string) query("id")))) return 0;
	msg="һ���װ����ֵİ����ӣ���Ϊ��̫���ˣ�����Ҫ����ϴ�衣
��������Լ��ʮ���ꡣ
����òƽƽ��
���Ŀ����֣��书�����������������������ƺ����ء�\n";

	if(obj->query("max_kee")) {
		msg += "��" + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 
				/ (int)obj->query("max_kee")) + "\n";
	}
	msg+="��������(Cloth)\n";

	tell_object(me, msg);
	return 1;
}
void reset()
{
	set("vendor_goods", ([
    __DIR__"obj/dogmed":100,
        ]) );
}
