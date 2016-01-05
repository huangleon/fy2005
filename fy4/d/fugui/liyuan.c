inherit ROOM;
#include "/questnpc/lovestory1/event_place.h"
void create()
{
	set("short", "��԰");

	set("long", @LONG
������Ǹ���ɽׯ�ġ�ʥ�ء���԰��֮��������˵����Ϊ������������˵����
��������ζ�Ŷ��˿����ü�ֻ���ӳ伢��������Ҫ���ǣ��Ƴ������ˣ�Ҳ��ժ����
����ȥ���ƺȣ�ʱ�����������ԭ���������������ִ�����ӣ�������ȴ�Ѿ���
ժ�ü�����ʣ�޼��ˡ�
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("exits",([
		"west":__DIR__"shibanlu2",
	]) );
        set("objects", ([
		__DIR__"obj/pear" : 2,
	]) );
	set("coor/x",30);
	set("coor/y",210);
	set("coor/z",80);
	setup();

}

int valid_enter(object me)
{

	if(me->query("lovestory1"))
		add_trigger_count(me);
	return 1;
}

void reset(){
        object item;
        int i;
        ::reset();
      
	if(!present("pear", this_object())){
                for (i=1; i<=2 ; i++) {
                	item = new(__DIR__"obj/pear");
	                if(objectp(item)){
                        item->move(this_object());
                	}
	        }
        }
        return;
}         