//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
        set("short", "ɳ̲");
        set("long", @LONG
��������ѷֲ��������˼䡣������ã�ɳ̲�����ϸ����ˮտ����̣���
�δ������������İ�ĭ�����ź�������Ŀ�������������죬�����к������ӱ̿գ�
���������׺��������ᷫ����������������������������˽���������
LONG
           );
        set("exits", 
           ([ 
 	     "west"  : __DIR__"beach",
 	     "east"  : __DIR__"seaside",
	    ]));
	
	set("objects", 
	   ([ 
	    ]));
        set("outdoors", "baiyun");
	set("coor/x",70);
	set("coor/y",-250);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
