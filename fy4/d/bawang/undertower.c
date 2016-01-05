#include <ansi.h>
inherit ROOM;
void close_path();
string broketower();
void create()
{
	set("short", "������");

	set("long", @LONG
�����濴��ȥ����ԭ����˵��ʮ����Ķ����Ե��쳣���ʣ�Խ���߽���Խ����
�ƺ���ѹ��͸�����������޴��ɽ����Ӱ��Ͷ������ں�����һƬ��ʲôҲ����
����Ҳûʲô������ֻ������һ����������ɽ����ɪɪ���졣	
LONG);
	set("long_night", @LONG
ҹ�ڷ�ߣ����ºں���һƬ���������Ͼ͸���Ҫָ������ʲô������Լ������
�����µĲݴ����ƺ���������˽�
LONG);

	set("exits",([
		"northeast":__DIR__"shanlu3",
	]) );
	set("item_desc", ([
		"����" : (: broketower :), 	
		"broketower" : (: broketower :),
		"tower" : (: broketower :),
	]));
	set("outdoors", "bawang");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
}

void init (){
	add_action("do_listen", "listen");
}

string broketower(){
	object me;
	
	me = this_player();
	if(!query("exits/enter")){
		tell_object(me, "������һСľ�������š�\n");
		add_action("do_push", "open");
	} else {
		tell_object(me, "����һƬ��ڣ���ʲôҲ�����塣\n");
	}
	return "";
}

int do_push(string arg){
	object room, me;
	me = this_player();
	
	if (arg == "door" || arg == "ľ��") {
		if(query("exits/enter")){
	        return notify_fail("���Ѿ����ˡ�\n");
		} 
		message_vision("$N������ľ����һ�ƣ�֨ѽһ��ľ�����ֶ�����\n", me);
		set("exits/enter", __DIR__"broketower");
		call_out("close_path", 4);
    	return 1;
    } 
    return 0;
}

int do_listen(string arg){
	object me, room;
	
	me = this_player();
	if(NATURE_D->is_day_time()){
		message_vision("����һƬ�ž���ż�������紵��Ҷ�Ļ�������\n", me);
		return 1;
	}
	if(query("exits/enter")) {
		return 1;
	}
	tell_object(me,HIY "ֻ�����������˻���˵���������Ȼ�Ѿ����ˣ���վ�������ʲô����\n"NOR);
	message("vision",me->name(me)+"ͻȻפ�㣬�ƺ��ڲ��������ʲô��\n", environment(me),me);
	message_vision(HIW "\n�Աߵ��������´ܳ�һ����Ӱ�����˶����µ�һ��С�ţ����˽�ȥ��\n"NOR, me);
	set("exits/enter", __DIR__"broketower");
    call_out("close_path", 5);
   	return 1;
}

void close_path(){
	if(query("exits/enter")) {
		message("vision", "С�š�֨ѽ��һ�����ֹ����ˡ�\n",this_object());
		delete("exits/enter");
	}
}
