inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�����ܸߣ���С�����������������һ��ĵط����Һ�����Ҳ���ܣ���������
����Ѿ֦�������׾��ҵ�Ъ�ŵĵط�����������Ժ�����ؿ���ֱ���µ�Ժ�����
��������Ժ��ļ�ֻ�������ڵ���Ѱʳ���������Ľ����������������
LONG
        );
        set("objects", ([
                
        ]) );

        set("exits", ([ 
  		"down" : __DIR__"temple5",
	]));
        set("coor/x",-1900);
	set("coor/y",720);
	set("coor/z",20);
	set("map","zbwest");
	setup();

}

void init(){

	add_action("do_climb","climb");
}

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg) {
		tell_object( me, "������ʲô��\n");
		return 1;
	}
	
	if (arg == "tree" || arg == "��"){
		tell_object( me, "�ţ���ô���Ŀ����أ�\n");
		return 1;
	}
		
	if (arg=="pine"|| arg=="����" || arg == "������") {
		room=find_object(__DIR__"pine2");
		if (!objectp(room)) room=load_object(__DIR__"pine2");
		message_vision("$N�ֽŲ��ã����ݵؼ�����������ȥ��\n",me);
        tell_room(room, this_player()->name() + "����������������\n");
        this_player()->move(room);
      	return 1;
      }
      
      return notify_fail("������û������\n");
}

