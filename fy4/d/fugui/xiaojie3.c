inherit ROOM;

void create()
{
	set("short", "��ʯС��");

	set("long", @LONG
��������������С�򣬽ֵ�����խ��Щ�������е㶸б�����ֺܾ���ֻ������
�ҵĴ������ȼ�Ű����ĵƻ��ؽ�Ʈ��һ����Ѽ��������ζ��ԭ�����׾�����
�Ϲ�������꣬�����治ʱ���˽���������������������֣�ȴ�Ǹ�������Ψһ
�ġ���Դ���̡���
LONG);

	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"liyuanpu",
		"west":__DIR__"duckshop",
		"south":__DIR__"xiaojie4",
		"north":__DIR__"xiaojie2",
	]) );
	set("coor/x",20);
	set("coor/y",90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
