inherit ROOM;

void create()
{
	set("short", "����԰");

	set("long", @LONG
�����������������ܾ��Ǵ���԰��������������ÿ�������°׵���ҹ������
ɽׯ�����������Ǳ�����ˣ�һ�����Σ�һ����裬���Ǻ��˰������������ϧ��
���ܾ��Ѿ�û��������ˣ����ǻ�ʱ���������ֵ��ǿ�����Ǯ���ƣ��긴һ�꣬��
��԰�е�����ҲԽ��Խ�١�
LONG
	);
	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"east":__DIR__"wuzhuxuan",
	]) );
	set("objects",([
		__DIR__"npc/yafeng":1,
	]));
	set("coor/x",-20);
	set("coor/y",210);
	set("coor/z",80);
	setup();
	setup();
	replace_program(ROOM);
}
