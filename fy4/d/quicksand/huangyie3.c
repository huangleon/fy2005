
inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١������������
�綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���ѪȾ���һ����һ����
�����۵Ĺٵ��������Ͷ�����չ��
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"huangyie0",
  "northwest" : __DIR__"huangyie1",
]));
        set("outdoors", "quicksand");
	set("coor/x",-1005);
	set("coor/y",-5);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
