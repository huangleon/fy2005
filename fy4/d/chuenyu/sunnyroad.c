// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "ɽ������");
        set("long", @LONG
������ïʢ�ĵ������һ���峺���׵�СϪ��������������������æµ�š�
�ٱ����Ǻ���ɽ������ɽ�������ƺ����Կ���һ���ľ߹�ģ�ĳǱ����Ǳ������
����һ����죬������������������Ľ��֣����ڡ�
LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"dustyroad2",
	]));

	set("objects", ([
               __DIR__"npc/xiaojuan" : 1,
	]) );
	set("no_fight",1);
	
	set("outdoors", "chuenyu");
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
}

void reset()
{
	object room;
	::reset();
        if(query("exits/north"))
        	delete("exits/north");
}



int valid_leave(object me, string dir)
{
	if(query("exits/north"))
		call_out("close_path",10);
	return 1;	
}


int close_path()
{
	reset();
	return 1;
}


