inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������һ���������Ų������ĳ߿������ſڵĵƹ����㹻������������������
�İ�����������ͷ��һ��ǽ�ڣ���û��ˮ�����Ҳû�����˵���ħŮ�����Ų���
һ�ɣ������ĵ���������ݣ�һֱ������ǽ��Ϊֹ�����һ�ɵĵط�������û��
���档��֮�»谵һƬ���谵֮�и��������Ĺ�Ӱ��
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"pingfeng",
		"eastdown": __DIR__"andao2",
	]));
        set("item_desc", ([
	
	 ]));
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
