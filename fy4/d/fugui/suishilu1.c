inherit ROOM;

void create()
{
	set("short", "��ʯС·");

	set("long", @LONG
����һ��ͨ����������ʯС·��·����������̦��һ�����ľͻ���������಻
֪����Ұ�����õ�Ҳïʢ��������ɢ����һ�����µĻ��㡣�����ż������һ����
��Ľ�����һ̧ͷ�����Կ��������������״��������ӥ״�ķ��ݸ߸߷�������
������С�
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "out":__DIR__"damen",
		"north":__DIR__"fuguitin",
	]) );
        set("objects" , ([
	    __DIR__"obj/flower" : 1,
        ]));

	set("coor/x",10);
	set("coor/y",200);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
