inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
����һ��ͨ������ɽׯ�����ɽ�������԰�ݵ������Ϧ���¿�������ƽ�
��صĻƽ�ʯ�����ɵ�С��б���Ϸ���չ������ƽ���е�һ�����񡣷��ڴ�����
������౵����ϳ��ֱ����ֻ����������������������������ڶ��ϵ����
ɽ�����Ż����������ݵ�������������������������ڴ˵����˴󶼲��Խ���ͣ��
�˽Ų���פ��С�.
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "eastdown":__DIR__"shandao8",
        "northup":__DIR__"shandao6",
	]) );

	set("coor/x",10);
	set("coor/y",130);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
