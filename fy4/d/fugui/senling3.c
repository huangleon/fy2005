inherit ROOM;

void create()
{
	set("short", "���־�ͷ");

	set("long", @LONG
�����ߵ������־�ͷ���㲻���������˿�������������ǰ�ߣ����ܲ�ľ��ϡ��
��ʯ������·����ϡ���Կ�������С����ĺ��ǣ�һ�ִ̱ǵĶ�����������̲�ס
��ҪŻ�£��������٣�ǰ����Ȼ���Ǹ���ڵ�ɽ��������ѣ�ε�����ӭ��������
LONG);

	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"south":__DIR__"senling2",
		"north":__DIR__"senling4",
	]) );
        set("objects", ([
		__DIR__"obj/skeleton" : 1,
        ]) );

	set("coor/x",-20);
	set("coor/y",250);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
