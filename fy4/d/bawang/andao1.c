inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
����һ�����������Ƕ���ɽ�ϵ�ǿ���ǰѲƱ��Ӷ��������������Ľݾ�������
��Ȼ�ܾ��Ѿ�û�������ˣ�������ʪ�Ŀ���������ָ���ĳ������̼����㼸��
���۾�����������
LONG);

	set("type","street");
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",-10);
	set("exits",([
		"southup":__DIR__"andao2",
		"out":__DIR__"undertower2",
	]) );
	setup();
	replace_program(ROOM);
}
