inherit ROOM;

void create()
{
	set("short", "����ɽ·");

	set("long", @LONG
����һ��ͨ������ɽׯ�����ɽ�������԰�ݵ������Ϧ���¿�������ƽ�
��صĻƽ�ʯ�����ɵ�С��б���Ϸ���չ������ƽ���е�һ������һ̧ͷ����
�Կ��������������״��������ӥ״�ķ��ݸ߸߷�������������С�
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "southdown":__DIR__"shandao7",
        "northup":__DIR__"shandao5",
	]) );

	set("coor/x",10);
	set("coor/y",140);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
