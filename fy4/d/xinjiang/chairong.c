/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "���ݱ���");
        set("long", @LONG
���ݱ����ڰ���ı����ʮ���ﴦ��ˮƽ�羵����ɼ��ˣ�ʢ����з����Щ
�ط��ĺ�ˮ��������Կ������׵�ʯͷ����ʯ���д����С�㣬ż�����м�����
��ð��ˮ�棬���������๾�࣢��������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"tulu3",
  "south" : __DIR__"baiyang",
]));
        set("objects", ([
        AREA_PALACE"npc/fish" : 2,
	AREA_PALACE"npc/shrimp" : 2,
                        ]) );
	//set("no_pk",1);
	
	
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","���ݱ���ˮ");
        set("liquid/type", "water");
        set("liquid/container","���ݱ���");
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}
