// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ�ݲ���ʯͷ�Ǿ͵�ȡ���ڸ���ɽ�ϲɵģ���ɫ��ʯ���쳣�ĺ�ʵ����ʹ��
���յ�����Ҳɹ����͸��Сʯ�ݵ��ſ��м��Ű��������ݺ���һ��СϪ����������
һ��ʯ������ʯ�ʣ������ϰ���һ��С���ӡ����Ӻ�һ����û���깤�������ӣ�
�Ա�һ����ɰ��ߣ�С������������̵Ĳ�ˮ����ǽ����һ��ľ����ǽ�Ƕ���һЩ
���ι�״��ʯ�顣
LONG
        );

    set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"stoneroad",
	]));

	set("objects", ([
		__DIR__"npc/yujiang" : 1,	
	]));
    set("indoors", "guanwai");

	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

