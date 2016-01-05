#include <ansi.h>
inherit ROOM;
string jinqi();
void remove_flag();
void create()
{
        set("short", "��ͤ��");
        set("long", @LONG
С·����һ�䡣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ�߾��Ǹߴ�ķ��Ƴ�
��ǽ�ˡ��ӵ��ϳ������̲ݡ�΢�����һ����������Ϣ��������һ����ͤ��һ����
�˺�һ��С������æ���к����ˣ����������ⲻ��·��һ��Χ��һ��Ⱥ�ˣ�����
���˸����ӣ����²���һ��[33m����[32m��
LONG
        );
    	set("exits", ([ /* sizeof() == 4 */
  		"north":__DIR__"tea_ting",
  		"northeast" : __DIR__"road3",
		"southwest" : __DIR__"road1",
	]));
	set("objects", ([
	    __DIR__"npc/badkid" : 1,
	    __DIR__"npc/laotou" : 1,
	    __DIR__"npc/thinmonk":1,
	    __DIR__"npc/qiuranke":1,
	    __DIR__"npc/hongfunv":1,
	]) );
    	set("item_desc", ([
		"jinqi" : (: jinqi :),
		"����" : (: jinqi :),
		"flag" : (: jinqi :), 
    	]) );
	set("have_flag", 1);
        set("outdoors", "fengyun");
	set("coor/x",-200);
	set("coor/y",200);
	set("coor/z",0);

        setup();

}

string jinqi(){
	object me;
	me = this_player();
	if(!query("have_flag")){
		tell_object(me, "û�������ˡ�\n");
		return "";
	}
	tell_object(me, HIY"                      �� �� �� ��\n"NOR);
    	tell_object(me, "            �׵��޼۱���     ��������������\n");
	tell_object(me, "\n��������ʮ�����£���δȢ�ף���ʤ��СŮһȭһ�ŵģ����¼���СŮ������\n");
	tell_object(me, "�������Ƴ����Ի�����֮�أ�������ʿ�ض࣬��Ϊ�����ٻ�������Ӣ�ۺ�����\n");        
	tell_object(me, "�������ߣ�����һժ(�����飩����������죡\n");
	return "";
}

void init(){
	add_action("do_zhai", "zhai");
}

int do_zhai(string arg){
	object me, qiu, hong, qi;
	me = this_player();
	if(!arg || (arg != "flag" && arg != "jinqi" && arg != "����")) {
		return 0;
	}
	if (!query("have_flag")){
		tell_object(me,"�Ѿ���ժ���ˡ�\n");
		return 1;
	}
		
	message_vision("$N��������ȥժ�졣\n", me);
	qiu = present("qiuran han", this_object());
	hong = present("redcloth girl", this_object());
	if(objectp(qiu) && objectp(hong)){
		qiu->zhaoqin(me);
	} else {
		message_vision("$Nժ��һ��С������뻳�С�\n", me);
		remove_flag();
		qi = new(__DIR__"obj/qi");
		qi->move(me);
	}
	return 1;
}

void remove_flag(){
	set("have_flag", 0);
	set("long", @LONG
С·����һ�䡣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ�߾��Ǹߴ�ķ��Ƴ�
��ǽ�ˡ��ӵ��ϳ������̲ݡ�΢�����һ����������Ϣ��������һ����ͤ��һ����
�˺�һ��С������æ���к����ˣ����������ⲻ��
LONG);
}

void reset(){
	::reset();
    set("long", @LONG
С·����һ�䡣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ�߾��Ǹߴ�ķ��Ƴ�
��ǽ�ˡ��ӵ��ϳ������̲ݡ�΢�����һ����������Ϣ��������һ����ͤ��һ����
�˺�һ��С������æ���к����ˣ����������ⲻ��·��һ��Χ��һ��Ⱥ�ˣ�����
���˸����ӣ����²���һ��[33m����[32m��
LONG
        );	
	set("have_flag", 1);
}