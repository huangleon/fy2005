// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ҩ��");
        set("long", @LONG
�������ڣ������ڶ࣬�����ɸ�������������黭����ҩ����޲���ͨ��
��������ɽ�У�����ҩ���ڶ࣬����ҩ��֮�е�ҩ����ҩ����Ʒ������������֮Ч��
�������Դ�С����������ɢ������ɢΪ����֮����������ѧ֮ʿ�޲���������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bingeast",
]));
        set("objects", ([
                __DIR__"obj/keedrug" : 2,
		__DIR__"obj/keedrug2" : 1,
		__DIR__"obj/dan" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
