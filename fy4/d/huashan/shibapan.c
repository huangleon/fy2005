
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
  		"northeast" : __DIR__"shaluo",
  		"southeast" : __DIR__"shibapan1",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-15);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init(){
	object me, jingji, obj;
	me = this_player();
	if(me->query("����B/�䵱_��Ҷ") && !present("jingji", this_object())) {
		jingji = new(__DIR__"obj/jingji");
		jingji->move(this_object());
		obj = new(__DIR__"obj/book");
		obj->move(jingji);
	}
}
