//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{        set("short", "�껨��");
    set("long", @LONG
����Ƭ�̣��������أ��������졣��Ȫ��ʯ��������䡣��ǰ�����ǻ������߳�
�����������������������Ի��ǻ��ԡ�ǰ���������ϵľ�����ͷ���и��������ߵ�
ˮ�󡣺쳾�����еķ������ˣ������ѱ�������������ɽ�⡣ˮ�����⣺
                           ��    ��
                           ��    ��
                           ��    ��
                           ��    ��
LONG
    );
    set("exits",
      ([
	"southwest" : __DIR__"feixianting",
	"northdown" : __DIR__"maze1",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	__DIR__"npc/huayin" : 1,
	__DIR__"obj/stone" :1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-55);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
