
inherit ROOM;

void create()
{
    set("short", "佻˳���");
    set("long", @LONG
�����Ǹ��������С���Ǹ�����ԡ�ģ����������ʮɫ�Ĳʴ�����ζ�˱ǵĻ�
�꣬������������ض��ǣ�͸������ˮ�����Կ���������������޳��Ĵ��ȣ���
ͦ�����ţ����ںڵĳ���������������
LONG
    );
    set("exits", ([
	"north" : __DIR__"hfenglang1",
	"south" : __DIR__"hfenglang3",
      ]));
    set("no_magic",1);
    set("coor/x",-80);
    set("coor/y",-250);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
