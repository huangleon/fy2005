
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
С�ֵ�������һ��ƽ������������ͨ�������ש���ĺ�Ժ��ס������Ĵ��
���ǿ����ճԷ��ģ��п�С�ӻ��̵ģ����ģ������ģ���ľ�ģ�Ҳ�е��ǳ��걼
�����������ԭ�������ˡ�
LONG
        );
        set("exits", ([ 
		"north": __DIR__"mroad5",
		"south": __DIR__"mroad7",
		"west": __DIR__"house6",
		
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
	replace_program(ROOM);
}
