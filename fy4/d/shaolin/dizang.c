// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�زص�");
        set("long", @LONG
���ڻ谵����Ϊ���������ڤ����������һ��ͭ���ز������������ߣ�����
���������ޡ�����ǽ�ϱڻ����Ա��ϣ��ƺ��Ǿ���ͼ�����Ǳ�������������Ū����
�ס�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"qianfe",
]));
/*        set("objects", ([
                __DIR__"obj/herb" : 1,
       ]) ); */
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",20);
	setup();

}
