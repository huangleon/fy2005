// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object con,item;
        set("short", "��ɽ��®");
        set("long", @LONG
�ò����׹���������ǰ����һ�����嶥��Ȼ�м�é�ݣ����Ͼ�ȻҲ����������
����ɽ��®�������ڳ���򵥣�һ�ź�ľ���Ϸ��ż��ᾭ����Ͳ��ϡ��ز��ż�ֻ
�Ǻ�����ǽһ�����������顰��񷡱���֡�
LONG
        );
	set("exits", ([ 
	  "south" : __DIR__"tiesuo",
	]));
    	set("objects", ([
        	__DIR__"npc/mas1" : 1,
        	__DIR__"npc/mas2" : 1,
		__DIR__"obj/xi" : 1,
    	]) );
    
    	set("valid_startroom", 1);
    	set("no_lu_letter", 1);
	set("coor/x",-140);
	set("coor/y",10);
	set("coor/z",40);
	setup();      
}

void init()
{
        add_action("climbing", "climb");
}

void reset()
{
	object me,me2;
	:: reset();
	me2=present("master li",this_object());
	me=present("master liu",this_object());
	if(me) me->dismiss_team();
	if(me2) me2->dismiss_team();
	if(me && me2) me->add_team_member(me2);
}


int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "valley" || arg == "down" || arg == "�ȱ�")
        {
	       me = this_player();
	       if (me->is_busy())
	       		return notify_fail("��������æ��\n");
	       if (me->query_temp("huangshan/hs_climb_down"))
	       		return notify_fail("���Ѿ����������ˡ�\n");
	       message_vision("$Nץ��ͻ����ʯ�ǣ�������˳�Źȱ�������ȥ��\n", me);
	       call_out("fliping",4,me);
	       me->set_temp("huangshan/hs_climb_down",1);
	       me->start_busy(2);
	       return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}

int fliping(object me)
{
        if(!me->is_ghost() && objectp(me) && environment(me)==this_object()) {
        	me->move(__DIR__"kuzhu");
        	me->delete_temp("huangshan/hs_climb_down");
        	message_vision("$N˳�Źȱ�����������\n", me);
        }
        return 1;
}

