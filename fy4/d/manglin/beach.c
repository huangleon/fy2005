//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��������ѷֲ��������˼䡣������ã�ɳ̲�����ϸ����ˮտ����̣���
�δ������������İ�ĭ�����ź�������Ŀ�������������죬�����к������ӱ̿գ�
���������׺��������ᷫ����������������������������˽���������
LONG
           );
        set("exits", 
           ([ 
 	     "north" : __DIR__"southsearoad1",
 	     "west"  : __DIR__"beach1",
 	     "east"  : __DIR__"beach2",
	    ]));
        set("objects", 
          ([ 
	        AREA_BAIYUN"npc/yueyang" : 1,
	        AREA_BAIYUN"npc/husheng" : 1,
	    ]));
        set("outdoors", "baiyun");
	set("coor/x",60);
	set("coor/y",-250);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

