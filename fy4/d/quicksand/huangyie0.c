
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
	  	"east" : 	__DIR__"xiaodao3",
	  	"west" : __DIR__"huangyie4",
	  	"northwest" : __DIR__"huangyie2",
	  	"southwest" : __DIR__"huangyie3",
	]));
        set("outdoors", "quicksand");

	set("coor/x",-1000);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
