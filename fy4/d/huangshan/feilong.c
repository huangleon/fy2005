// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "������");
    set("long", @LONG
�������������ǰ�������ɽ���ն�����ʲô����ľ�ɫ������������ʿ��
ϲ������̽�ģ������и��������ڴˣ����Ժ����߸������ﲻ�����ڴ��ܹ��õ���
��˵�е��ر�������ɽ����ʯ�������Ӳݴ�����˿���������˵ļ��󣬵���˭Ҳ��
�Ϸ���ϣ������Ҫ��һ�ѡ�
LONG
        );
    set("exits", ([ 
  		"southeast" : __DIR__"qingliang",
	]));
    
    set("outdoors", "huangshan");
	set("coor/x",-130);
	set("coor/y",10);
	set("coor/z",30);
	setup();
}
void init()
{
	add_action("do_search","��");
	add_action("do_search","search");
	add_action("do_search","sou");
}
int do_search()
{
	string *names = ({"�����","���Ƶ�","˺������","մ�������"});
	object clo,me;
	me = this_player();
	clo = new("/obj/armor/cloth");
	clo->set("name",names[random(sizeof(names))]+"����");
	message_vision("$N�����ʯ�������Ӳݴ�����ɽ����ͣ����Ѱ�ţ���\n",me);
	if(!me->is_busy())
	{
		tell_object(me,"�㷢����һ��"+clo->name()+"��\n");
		clo->move(me);
	}
	me->start_busy(4);
	return 1;
}
