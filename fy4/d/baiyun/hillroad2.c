//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "ɽ�е�");
    set("long", @LONG
�в���Զ������ͻ�����ֵͷ�����˷������Ρ�����ǰ��Ȼһ����ɽ������ƽ
�ء���Ȼ����. ������ɽ��ˮ��ӳ֮�£���Ȼ��һ��ɽ�ǡ�
LONG
    );
    set("exits",
      ([
	"northdown" : __DIR__"hillroad",
	"enter" : __DIR__"baiyunwall",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([ 
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-110);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
