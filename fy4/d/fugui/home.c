inherit ROOM;

void create()
{
	set("short", "���");

	set("long", @LONG
����һ�������ķ��ݣ���ͽ�ıڣ��ݽǵ��׸��ǿյģ��������ڵ�ˮ��Ҳ�ǿ�
�ġ�����ȱ�첲���ȵ����ο�ǽ���š����������Ѿ���������ֵǮ�Ķ���ȫ������
�ˡ�
LONG);

	set("type","house");
	set("exits",([
	"west":__DIR__"xiaojie1",
	]) );

	set("objects",([
		__DIR__"npc/oldman":1,
	]));
	set("coor/x",30);
	set("coor/y",110);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
