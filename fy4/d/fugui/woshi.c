inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
�����ǹ���·����̫ƽ�����ҡ����Ӳ���Ҳûʲô���裬���߰�������Щ��
�����õľ����ǽ�ǲ�����֩�����������Ӷ��ǻҳ���Ǻ���㲻ס���ԡ�������
Ц�ԣ������������ֻ�й������������ܣ��������Ǵ�һ�����Ҫ��Ķ��ӡ�
LONG);

	set("type","indoors");
	set("exits",([
		"east":__DIR__"grass4",
		"south":__DIR__"grass1",
	]) );

	set("objects",([
		__DIR__"npc/yan":1,
		__DIR__"npc/lin":1,
	]));

	set("coor/x",0);
	set("coor/y",240);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
