
inherit ROOM;

void create()
{
    set("short", "��������");
    set("long", @LONG
�������������ι��ţ�ǰ����һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е�
���������һЩ�滨��ݡ��������������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ���
�㼸��Ҫ�������˲Ų��Ử����
LONG
    );
    set("exits", ([
	"south" : __DIR__"jlong",
	"north" : __DIR__"jlonglang2",
      ]));
    set("coor/x",-80);
    set("coor/y",-155);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}
