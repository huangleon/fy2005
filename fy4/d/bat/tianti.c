
#include <ansi.h>
inherit ROOM;

int do_noregret(string arg);
int do_regret(string arg);

void create()
{
    set("short", "���ݾ�ͷ");
    set("long", @LONG
�����������ţ�һ�ȣ�door1��ͨ�����棬�ǻ�·������һ�ȣ�door2��������
·��������ǿ������׵�������Ԩ��ֻҪһ��̤�£�����ٲ����ˣ�û����֪����
�������ǻ�·��������Լ�ѡ��ȥ���ţ���ֻҪһ�����ţ��ͷ��߳�ȥ���ɣ�����
����ˡ�
LONG
        );
    set("exits", ([ /* sizeof() == 0 */
        "down" : __DIR__"tianti3",

        ]));
    set("item_desc", ([
        "door1":
        "�����ż�������ȫһģһ���ģ�û�����ܿ������Ĳ���������Ĳ��\n",
        "door2": 
        "�����ż�������ȫһģһ���ģ�û�����ܿ������Ĳ���������Ĳ��\n",
        ]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",40);
    setup();
}

void init()
{
    add_action("do_open", "open");
    add_action("do_answer", ({ "answer" }));
    if (interactive(this_player()))
    if (userp(this_player()))
    {
    	remove_call_out("give_hint");
    	call_out("give_hint",5, this_player());
    }
}

void give_hint(object who)
{
    
    if (who)
    if (present(who)) message_vision(HIY"
�����������ѡ���㲻���������һ�����������������˺���������ǡ�
����ѡ����������"NOR"\n",who);
}

                  
int do_open(string arg)
{
    object room;
    if( arg == "door1" || arg == "door2")
    {
        if (this_player()->is_fighting() || this_player()->is_busy()){
        	tell_object(this_player(),"��������æ��\n");
        	return 1;
        }
        message_vision(HIB"$N�ƿ����ţ�ʧ�������������Ԩ�����뿪�������� 
һɲ�Ǽ䣬$P����ǰ�ָ��ֳ����İ����˵�Ц��... \n\n"NOR, this_player());
	    this_player()->set_temp("last_damage_from","������ʧ�����������Ԩ��\n");		
		this_player()->receive_wound("kee",this_player()->query("max_kee")*3/4);
		room = find_object(AREA_SHENSHUI"yadi");
		if (!room)	room = load_object(AREA_SHENSHUI"yadi");
		this_player()->move(room);
        COMBAT_D->report_status(this_player());
        return 1;
    }
    return 0;
}


/*
int do_say(string arg)
{
    object room;
    if( arg == "�������������������" || arg == "�Ҿ�����ڣ�" ||
        arg == "I won't regret!" || arg == "����������ͨ�ˡ�"||
        arg == "����������㹻��")
    {
        message_vision(HIY "$N�����ƿ���һ���ţ���ǰ�ֳ������ޱȵ�Ϧ��... \n"
                      NOR, this_player());
        room = load_object(__DIR__"anbian1");
        this_player()->move(room);
        return 1;
    }
    return 0;
}
*/

int do_answer(string arg) {
	
	object me = this_player();
	if (me->is_fighting() || me->is_busy()){
		tell_object(me,"�Ȱ���ͷ���¶�Ӧ������˵�ɡ�\n");
		return 1;
	}
		
	
	if (! arg) {
		tell_object(me,"����ش�ʲô��\n");
		return 1;
	}
	
	if (arg == "no regret" || arg == "�����" || arg == "������"|| arg == "��" || arg == "no"
		|| arg =="����") 
		do_noregret(arg);
	else if (arg == "regret" || arg == "���" || arg == "yes"|| arg=="��")
		do_regret(arg);
	
	return 1;
}
			

int do_noregret(string arg)
{
    object room;
    object me = this_player();
    
    tell_object(this_player(),HIW"�����Ҳ����ڵģ�����������������������Ѿ��㹻�ˡ�"NOR"\n");
    message_vision(HIY "$N�����ƿ���һ���ţ���ǰ�ֳ������ޱȵ�Ϧ��... \n"NOR,
                   this_player());
    room = load_object(__DIR__"anbian1");
    this_player()->move(room);
    
    if (QUESTS_D->verify_quest(me,"�´�����"))
		QUESTS_D->special_reward(me,"�´�����");
    
    REWARD_D->riddle_done(me,"�´�����",10,1);    
    return 1;
}

int do_regret(string arg)
{
    tell_object(this_player(),HIW"��һ��ҪС�ģ��������ϻ���̫�������û�����ꡣ"NOR"\n");
    return 1;
}
