inherit ROOM;

void create()
{
        set("short", "Ӫ��");
        set("long", @LONG
����Լ��ʮ�ɼ������������Ӷ��𼸸����Ρ��������뺷����������һ��Ⱦƣ�
б���۴������㡣��һ�������һ��ͷ�����������µ�ë�����ӣ�һ��ִ�ž�
����һ�ְ�����������ʯ���ĺ�������������۹�ɨ������ŭ������
LONG
        );
        set("exits", ([ 
	  	"south" : __DIR__"banditcamp1",
	  	"north" : __DIR__"innercamp",
			]));
	set("objects", ([
		__DIR__"npc/banditleader" : 1,
	]));

        set("coor/x",-440);
	set("coor/y",620);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

int valid_leave(object obj, string dir){
	int i;
	object bandit;
	if(dir == "north"){
		if (objectp(bandit=present("bandit leader")))
				return notify_fail(bandit->name()+"��ס�����·��\n");
		
	}	
	return 1;
}

void init(){
	add_action("do_look","look");
}


int do_look(string arg){
	if (arg=="north"){
		tell_object(this_player(),"���ںڹ�¡�˵أ�ʲôҲ���������\n");
		return 1;
	}
	return 0;
}