inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���£���һ��ʯ��������ʮ��ʯ��бб����չ��ȥ�����������������Ӱ����
������͸�����ġ��ƹ��У�����ͨ����ҫ�������ĺ�â��������Ϣ�͵�������Ī��
Ҳ��ĳ��а���벻���������
LONG
        );
        set("exits", ([ 
		"westup":  __DIR__"andao1",
		"eastdown":  __DIR__"andao3",
	]));
        set("item_desc", ([
	
	 ]));
	set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",-10);
	set("map","taiping");
	setup();
}
