/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
�����ǹ��ľ�ͷ����ʮ�ɸߵ����¾����Ǳ���һ���������ġ�һ�ɶ����ٲ�
һк���£��������¾�������������ĳ�У���Ϊ׳�ۡ��ٲ���һйǧ��֮�ƻ���
���У�¡¡֮�������ڶ���
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"goudi2",
  		"eastup" : __DIR__"aiding",
	]));
        set("objects", ([
        	__DIR__"npc/serpent" : 1,
                        ]) );
		
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","������ˮ");
        set("liquid/container", "����������ٲ�");
	set("coor/x",40);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}
