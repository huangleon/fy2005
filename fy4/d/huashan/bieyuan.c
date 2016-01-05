#include <ansi.h>
inherit ROOM;
string tree();
void create()
{
        set("short", "��ɽ��Ժ");
        set("long", @LONG
��ɽ��ԺΪһ������԰�֣�ռ��ʮ��Ķ������ǰ��ˮ���񣬹��ڹ�����涣���
�����滨��ݽ����ӳ��Ժ�ڸ���һ������������˵�Ǵ�ӡ�����������֣�ÿ�껨
���׻����࣬�������ˡ�
LONG
        );
    set("exits", ([ 
  		"west" : __DIR__"shaluo",
		"east" : __DIR__"zhengtang",
	]));
	set("item_desc", ([
		"tree" : (: tree :),
		"������" : (: tree :),
	]) );   
	set("objects", ([
		__DIR__"npc/linger" : 1,
	]));
    set("flower_amount", 4);
    set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

string tree(){
	object me;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	message_vision("$Ņͷ����������ȥ��\n", me);
	if(i != 2) {
		tell_object(me, "������֦Ҷï�ܣ��޴�������ڱ��˰�����ա�\n");
	} else {
		tell_object(me, HIW"\n��������֦Ҷï�ܣ�Ũ�ܵ�֦Ҷ���׺�Ű�ɫ�Ļ��䣬�����������Ʈ����\n"NOR);
		if(query("flower_amount") >= 0) {
			tell_object(me, HIW"������ڴ�İ׻����㴥�ֿɼ���֦���ϡ�\n"NOR);
			add_action("do_pick", "pick");
		}
	}
	return "";
}

int do_pick(string arg){
	object me, flower;
	me = this_player();
	if(!arg || (arg != "flower" && arg != "�׻�")){
		return 0;
	}
	message_vision("$N����ժ����һ���ɫ�Ļ��䡣\n", me);
	flower = new(__DIR__"obj/flower2");
	if(objectp(flower)){
		flower->move(me);
	}
	add("flower_amount", -1);
	return 1;
}

void reset(){
	::reset();
	set("flower_amount", 4);
}
