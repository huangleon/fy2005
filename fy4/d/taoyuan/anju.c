inherit __DIR__"no_killing_place";
void create()
{
        set("short", "��Ȼ��");
        set("long", @LONG
ԭľΪ�飬�����������ִ�Χ��һ��Ժ�䡣����ķ紵���ԭľ�����ٲ���
û�и��ã��������˸��������˱��̵�Ҷ�ӣ����̵���ʱ���һ����ζ�����Ų���
��̣�����Ҳ�ƺ������ں��������Ը��飺��������Ե��ɨ  ���Ž�ʼΪ��������
�к��飺��Ȼ�ӡ�
LONG
        );

    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"road3",
	]) );

	set("objects", ([
		__DIR__"npc/dog" : 1,
	]) );

	set("item_desc", ([
		"door" : "������̵Ĳ���ֻ�������ţ��ƺ�����һ�ƾͿ��ˡ�\n",
		"����" : "������̵Ĳ���ֻ�������ţ��ƺ�����һ�ƾͿ��ˡ�\n",
	]) );

	set("no_magic", 1);	
   	set("outdoors","taoyuan");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}

void init() {
	::init();
	add_action("do_push", "push");
} 

void close_path()
{
	if( query("exits/north") ) {
    message("vision","�������ص��˼�����������ھ�ֹ�ˡ�\n",this_object() );
    delete("exits/north");
    }
}

int do_push(string arg)
{
	object me;
    me = this_player();
    if( arg=="door" || arg =="����") {
    	message_vision("$N�������������һ�ƣ�֨��������һ�����ſ��ˡ�\n", me);
		set("exits/north", __DIR__"cyard");
		call_out("close_path", 5);
	}
	else {
		write("��Ҫ��ʲô�أ�\n");
	}
	return 1;	
 }
