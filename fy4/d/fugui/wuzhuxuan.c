inherit ROOM;

void create()
{
	set("short", "����������");

	set("long", @LONG
������ǡ���������������Ҳ���������������ӵ�Ժ��һ����ԭ�ȱ��С�����
���������ǵȵ����������˵�ʱ�򣬾��������˸����֣��С�����������������Ϊ
�����á����������ֱ�������ţ�����ȴ�ѱ�ú��ס�����Ϊ��һ���á�����
������������Ȼ�Ǹ��ܷ��ŵĴ����ˣ����ڰ�ʮ���á��������������˾����ײ�
���͵ı����ˡ��������涼���˺ܴ�Ĵ��ӣ�������ȥ���������Ĵ���
LONG);
	
	set("type","house");
	set("indoors", "fugui");
	set("exits",([
        "east":__DIR__"suishilu2",
		"west":__DIR__"cuizhuyuan1",
		"south":__DIR__"cuizhuyuan2",
		"north":__DIR__"cuizhuyuan3",
	]) );

	set("coor/x",-10);
	set("coor/y",210);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
