
inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
��ã�ı�ѩ֮���ϣ���ɫ��¯���յ�������������ˮ����С���н�֯��һ����
�����Ȼ�Ĵ����Ӻ���������Ż��̵Ĵ󴸣�һ��һ���Ȼ������������ǰ��
���飬��ߵı�Ͱ�н������Ѵ�õı��С�
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"downtown",
]));
        set("objects", ([
		__DIR__"npc/alone":1,
						]) );


	set("coor/x",-50);
	set("coor/y",30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

