inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����С��");
        set("long", @LONG
С�����û�еƹ⣬һ�㶼û�С�һ��˵��������ɭ������������ͬ���
ʯ���·����ʯ����Ұ�ݾ�������ߣ���Ȼ��ط�ƽʱ���������������������ǰ�
��ɫ�ĸ�ǽ��û�д��ӣ�Ҳû��������
LONG
        );
        set("exits", ([ 
		"west": __DIR__"droad1",
		"east": __DIR__"droad3",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
 		"grass":	"С�����ˣ�Ұ���Ѿ���������ˡ�\n",
		"Ұ��":		"С�����ˣ�Ұ���Ѿ���������ˡ�\n",    
	]));
	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();

}

void init(){
	if (random(2)) {
		remove_call_out("event_msg");
		call_out("event_msg",random(5)+1);
	}
}

int event_msg() {
	message("vision",HIG"�����һ�������εĴ���ɹ���������������������\n\n"NOR,this_object());
	return 1;
}