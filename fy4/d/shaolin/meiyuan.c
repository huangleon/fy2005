// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "÷԰");
        set("long", @LONG
��Ķ������԰�ӣ�������÷����԰��÷֦��б�����������¡������徻���࣬
�ƺ�������������ɨ�� 
LONG
        );
        set("exits", ([ 
 	 "east" : __DIR__"banruo",
  	"west" : __DIR__"shan",
	]));
    
       set("objects", ([
//               __DIR__"obj/meizhi" : 1,
       ]) );
       
    set("outdoors", "shaolin");
	set("coor/x",-5);
	set("coor/y",120);
	set("coor/z",20);
	setup();
}

/*
void init()
{
	object me,meizhi;
	if (!random(50))
	{
		if(interactive(me = this_player()) && !me->is_fighting() && userp(me))
		{
			if (!present("meizhi",this_object()))
			{
				meizhi = new(__DIR__"obj/meizhi");
				meizhi->move(this_object());
			}
		}
	}
}

*/