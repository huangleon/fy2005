//Sinny@fengyun 2003
//All Rights Reserved 
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
���������һ���Ϊ������ͥԺ��ͥԺ��Χ���Ż�Ҳ����ֵĲ�ͬ��������һ��
��ߵ�̨��֮�ϡ�������Χ�и�̨���ƣ����Եý�����ĸߴ���������䣬�پ���
С��ͥԺ���ģ������ɺ繰�ź������ăȽ�ˮ�ӵ��ݺύ֯���׵�ʯ���˴�����
�䡣
LONG
    );
    set("exits",
      ([
	"north" : __DIR__"skystreet2",
	"south" : __DIR__"yuequedian",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	__DIR__"npc/guard1" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-200);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
