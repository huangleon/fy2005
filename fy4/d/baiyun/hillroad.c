//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "ɽ�е�");
    set("long", @LONG
�в���Զ������ͻ�����ֵͷ�����˷������Ρ�����ǰ��Ȼһ����ɽ������ƽ
�ء���Ȼ����. ������ɽ��ˮ��ӳ֮�£���Ȼ��һ��ɽ�ǡ�
LONG           );
    set("exits",
      ([
	"northdown" : __DIR__"duixiuhill",
	"southup" : __DIR__"hillroad2",
	"northeast" : __DIR__"guajianbei",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([ 
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-100);
    set("coor/z",20);
    setup();
    replace_program(ROOM);
}
