// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Сɽ��");
        set("long", @LONG
һ��СС��ľ�ţ����˿��أ����������ڽ�ȥ�����˾��Բ�����ʮ�������Ǵ�
ĦԺ�ĳ��ϣ�����������ʮ�����ɮ����δ����ȥһ���������ߴ���û�г�������
�����ź󾿾���ʲô�Ѿ���Ϊ���ֺ�ɮ�������������⡣
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"meiyuan",
  "west" : __DIR__"diyuan",
]));
        set("objects", ([
                __DIR__"npc/owner" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",120);
	set("coor/z",20);
	setup();
}


int valid_leave(object me,string dir)
{
	object ob;
	if(userp(me) && dir == "west" && ob=present("xie zhanggui",this_object()))
	{
		if (!me->query_temp("marks/pass_xiezhanggui")&& !REWARD_D->check_m_success(me,"������¥"))
		{
			message_vision("$N��$n�����٣������治С�����ȥ��û�Ŷ���\n",ob,me);
			return notify_fail("");
		}
	}
	return 1;
}

