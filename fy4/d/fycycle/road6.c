inherit ROOM;
void create()
{
        set("short", "�Ƕ�С��");
        set("long", @LONG
���Ƿ��ƳǶ���һ��С����Ҳ�Ǵ�����С��ȥ�����Ƴǵıؾ�֮·��·�ϵ�Ҳ
�в������ˡ�·�ߵĻ��Ǻ�����ˮ������������ȥ����һ������ɫ��ɽ�壬��ɽ
�ĵ�·�������档
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 	 "south" :	__DIR__"fyeast",
  	"northwest" : __DIR__"road5",
]));
        set("outdoors", "fengyun");


	set("coor/x",320);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}


void init()
{
	add_action("do_north", "enter");	// annie: no hint here since i assume they pass from the other side 1st.
}



int do_north(string arg)
{
    object room, me;
		me = this_player();
		if (!room= find_object("/d/fy/stone2"))
			room=load_object("/d/fy/stone2");
		tell_object(me,"\n���������������ܿ���֮�裬������������ô�������Ѷ���������ʲô��\n");
		me->ccommand("emote С������ذϹ����Ǻӣ�һ��������ǽ�ϵ�һ��������ȥ��\n");
		me->move(room);
		me->ccommand("emote �ٺ�һЦ���ӹ��������˳������������֡�");
		if (!REWARD_D->check_m_success(me,"��������"))
				REWARD_D->riddle_done(me,"��������",1,1);
		me->set_temp("body_print", "��������մ���˺����ˮ�����εδ����������䣬\n�������ö��İ���");
		return 1;
}

