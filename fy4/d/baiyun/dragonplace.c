//Sinny@fengyun 2003 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
    set("short", "��̨");
    set("long", @LONG
·�Եİ�ʯ����ǧ�ٸ���������׵�ͶӰ������һ��ɫ�������ˮ�ʻ������죬
������׵�ǧ����ˮ��ʤ����Ȫ����εΪ��ۡ�һ�����¿��̤ˮ�Ÿ裺
                           ��    ǧ
                           ��    ��
                           ��    ׳
                           ��    ־
LONG
    );
    set("exits", 
      ([ 
	"southup" : __DIR__"yanchilou",
	"northdown" : __DIR__"feixianting",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/jiandan" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-30);
    set("coor/y",-65);
    set("coor/z",10);
    setup();
    replace_program(ROOM);
}
