// Room: shibanlu4.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "��ʯС·");

	set("long", @LONG
������ʯС·�������Ǹ���ɽׯ�ĺ�Ժ�ˣ������Ǹ�����������·����������
̦��һ�����ľͻ���������಻֪����Ұ�����õ�Ҳïʢ��������ɢ����һ������
�Ļ��㡣�����ż������һ������Ľ�����һ̧ͷ�����Կ��������������״��
������ӥ״�ķ��ݸ߸߷�������������С�
LONG
	);

	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"south":__DIR__"fuguitin",
		"northeast":__DIR__"grass3",
		"northwest":__DIR__"grass1",
	]) );
        set("objects" , ([
	    __DIR__"obj/flower" : 1,
        ]));
	set("coor/x",10);
	set("coor/y",220);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
