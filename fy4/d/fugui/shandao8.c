inherit ROOM;

void create()
{
	set("short", "����ɽ·");

	set("long", @LONG
����һ��ͨ������ɽׯ�����ɽ�������԰�ݵ������Ϧ���¿�������ƽ�
��صĻƽ�ʯ�����ɵ�С��б���Ϸ���չ������ƽ���е�һ�����񡣷��ڴ�����
������౵����ϳ��ֱ����ֻ����������������������������ڶ��ϵ����
ɽ�����Ż����������ݵ�������������������������ڴ˵����˴󶼲��Խ���ͣ��
�˽Ų���פ��С��
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "westup":__DIR__"shandao7",
        "southdown":__DIR__"shandao9",
	]) );

	set("coor/x",20);
	set("coor/y",130);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
