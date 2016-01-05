#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʮ����");
        set("long", @LONG
�˴�ɽ�ƶ��ͣ���ɽ��·���ͼ�����·��ɽ�������̻���ʮ�а�����ɽ���ϣ�
·�Ծ����������㲻ʱ�ı�����ǣ���¹ڡ�
LONG
        );
    set("exits", ([ 
  		"southwest" : __DIR__"shibapan2",
  		"northwest" : __DIR__"shibapan",
	]));
	set("objects", ([
		__DIR__"obj/jingji" : 1,
		__DIR__"npc/explorer2" : 1,
		
	]) );

   	set("bird_came", 0);
    	set("outdoors", "huashan");

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

void init(){
    int i;        
    i = NATURE_D->set_season();
	if(i == 4){
		return;
	}
   	if(NATURE_D->is_day_time() && NATURE_D->get_weather() == "��" 
    		&& !query("bird_came")) {
		set("bird_came", 1);
        call_out("bird_come", random(30), this_player());
    }    
}

int bird_come(object me){
    object bird;
    
    if (!me)	return 0;
    if(environment(me) != this_object()) {
    	return 0;
    }

    bird = new(__DIR__"npc/ybird");
    if(objectp(bird) && !present("yellow bird", this_object()) ){
        bird->move(this_object());
        message_vision(YEL"\nֻ��һ����ɫ��Ӱ�Ӵ�����ǰ������һֻС��ȸ׹����·�Եľ������С�\n"NOR,
                bird);
        message_vision("һ����ɫ��Ӱ�Ӵ��ϱ��ӹ��������ͷ���ǻ��þò�ȥ��\n", bird);
    } 

}

void reset(){
	::reset();
	if (!random(8))
		delete("bird_came");
}
