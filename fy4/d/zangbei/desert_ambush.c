inherit ROOM;

void create()
{
        set("short", "ɳ��");
        set("long", @LONG
ɳ�𲢲���ת��ɳ�𣬾��Ƽ�һ���ˣ������ֱ�Ѳ��������ˣ�������һֻ
�����ڻ��ϣ��챻�����˵�����������ر��˶��ڵ��ϣ��������ף�������ϣ�
������ţƤ��ţƤ������ʪ�ģ���̫��ɹǬ�ᣬ��Խ��Խ����ֱǶ�����
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"yangguan1c",
		"north" : __DIR__"mirage",
		]));
	set("objects", ([
		__DIR__"npc/assassin" : 1,
		
	]));
	set("item_desc",([
	
	]));
	set("outdoors", "zangbei");
    set("coor/x",-90);
	set("coor/y",290);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}


void reset(){
	object man;
	::reset();
	set("long", @LONG
ɳ�𲢲���ת��ɳ�𣬾��Ƽ�һ���ˣ������ֱ�Ѳ��������ˣ�������һֻ
�����ڻ��ϣ��챻�����˵�����������ر��˶��ڵ��ϣ��������ף�������ϣ�
������ţƤ��ţƤ������ʪ�ģ���̫��ɹǬ�ᣬ��Խ��Խ����ֱǶ�����
LONG
        );
        if (man = present("trader",this_object()))
        	if (!man->is_fighting()) {
        		man->set("name","����");
        		man->set("chat_chance",1);
        	}
}
