inherit ROOM;

void create()
{
        set("short", "ľ��");
        set("long", @LONG
ľ������������бڵ�ľ��ȴ�Ѻܳ¾ɣ��е������Ѹ��ѣ������Ƕ������
���ݡ�����ֻ��һ�ŵͰ���ľ����һ���޴�Ļ��衣
LONG
        );
     
        set("exits", ([ 
		"west" : __DIR__"wallhole",
	]));
        set("objects", ([
                __DIR__"npc/yansong" : 1,
        ]) );

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}