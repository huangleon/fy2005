inherit __DIR__"no_killing_place";
void create()
{
    set("short", "����");
    set("long", @LONG
һ�䲢�������鷿��ȴ��ʰ����ˬ���ˡ��ұ��������֮�£�����һ����̴
���������������һ�Ž�ľ���٣������ںڹ�����û�а��ҳ�����������һ����
��Ͳ��ȴ����һ֦ɽ�䳣������Ҷ�����Ҳ��һ����̴����������бб��̯������
��װ�飬һ����裬�������¡��ݵ����У�������һ��������ã�

������������[1;37m���˶�˵���ɺã���ֻ��ԧ������[2;37;0m

LONG
        );
    set("exits", ([ 
        "south" : __DIR__"cyard",
        "east" : __DIR__"grassland",
	]) );

    set("item_desc", ([
	"�������": "һ��ī�ʿ���鷨��������ˮ�����ư��磬����һ��˵�����������к��������м䣮��\n",
	"writing": "һ��ī�ʿ���鷨��������ˮ�����ư��磬����һ��˵�����������к��������м䣮��\n",
	]) );
    set("no_magic", 1);
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
    setup();
}

void init()
{
	::init();
    add_action("do_search", "search");
}

int do_search(string arg)
{
    object me, obj;
    
    me = this_player();
    
    if(!arg || arg != "room" && arg != "�鷿") return 0; 
    if(me->query_temp("marks/marble") && !query("marks/gone"))
    {
        message_vision("$N���鷿�ڷ��䵹�������һ����\n", me);		
        tell_object(me, "�������ڽ�ľ���ٵ������ҵ���һ��Сˮ����\n");
        message("vision",me->name()+
                "͵͵�����شӽ�ľ�������ó��˸������ŵ����\n",
                environment(me), me);
        me->delete_temp("marks/marble");
        set("marks/gone",1);
        obj = new(__DIR__"obj/marble");
        obj->move(me);
        return 1;
    }
    message_vision("$N���鷿�ڷ��䵹�������һ����\n", me);		
    tell_object(me, "��ȴû����ʲô�м�ֵ�Ķ�����\n");
    return 1;	
}

void reset()
{
    ::reset();
    delete("marks/gone");
}
