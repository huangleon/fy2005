
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ï�ܵ����֣���ʱ�ܼ�����ֻ����������������ȥ����Ȼֻ�м�˿������͸��
���룬ȴ���Ե���ɭ�ɲ���ϰϰ���粻ʱӭ�洵����ʹ�˻����泩��ʹ����������
�˯��һ����
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"road2",
	]));

	 set("objects", ([
//			__DIR__"npc/oldtaoist1" : 1,
			__DIR__"npc/oldtaoist2" : 1,
			__DIR__"npc/oldtaoist3" : 1,
			__DIR__"npc/oldtaoist4" : 1,
			__DIR__"npc/oldtaoist5" : 1,
			__DIR__"npc/oldtaoist6" : 1,
			__DIR__"npc/oldtaoist7" : 1,
   ]) );

	set("no_lu_letter",1);
	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",-40);
	setup();
}


void reset()
{
	object *inv, ob;
	int i;
	::reset();
	ob=present("taoist elder", this_object());
	
	inv = all_inventory();
	if(ob)
	{
			ob->dismiss_team();
			for(i=0;i<sizeof(inv);i++)
	        if(inv[i]->query("id") == "taoist elder" && inv[i] != ob)
				ob->add_team_member(inv[i]);
	}
}

