
inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
С����Զ����һ��ɽ������Բ�����ɽ���������˹�����ĺۼ����丵�ϸ��
˳�Ŷ���������������������ˮ�������ƽ������ߣ����Ŵӳ��ڴ�͸�����⣬��
���ֽ��µ�ʯ����Ȼ�Ǻ������ɵġ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secret_road",
  "west" : __DIR__"another_sky",
]));
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

