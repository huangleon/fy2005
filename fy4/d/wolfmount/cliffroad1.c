inherit ROOM;

void create()
{
	set("short", "����ջ��");

	set("long", @LONG
һ�������������ͱڵ�ջ��������������֪ͨ��η���̧ͷ���Ͽ�ȥ��������
�ƣ�ɽ����Ũ�������������ɹ��֣�����ס�ջ�����ʧ�ޣ�ľ�ƻ����ϵĶϣ�
�۵��ۣ�һ��С�ľͲ���׹��������޵���Ԩ��
LONG);

	set("type","road");
	set("exits",([
		"westup":__DIR__"wolfhill",
        "southeast":__DIR__"cliffroad5",
	]) );
	set("coor/x",10);
	set("coor/y",40);
	set("coor/z",-30);
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/xueya":1,
    	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	object room;
	
	if (me->query("timer/insurance") + 259200 > time())
		return 1;
		
	if( userp(me))
	{
        switch(random(15))
		{
			case 0:
				message_vision("$N����һ��������������ջ���ϻ��˻Σ���\n",me);
				return notify_fail("���ã�û����ȥ��\n");
				break;
			case 1:
				inv = all_inventory(me);
				if(sizeof(inv)>=1)	
				{
					ob = inv[random(sizeof(inv))];
                    if (ob->query("no_drop") || ob->query("owner")
                    	|| ob->query_autoload() ) break;
					message_vision(ob->name()+"��$N���ϻ��˳���������������Ԩ��\n",me);
					destruct(ob);
				}
				return 1;
				break;
			case 2:
				message_vision("$N������ջ����ǰ����ϵػ���......\n",me);
                if ( me->query("kar") <= 22 )
				{
					message_vision("������һ��ɱ���������Һ���$Nʧ����������......\n",me);
					me->unconcious();
					room = find_object(__DIR__"undercliff");
					if(!objectp(room)) room = load_object(__DIR__"undercliff");
					me->move(room);
					return 0;
				}
				else
				{
					message_vision("$N��æ�������ϣ����ã����ڰ�ȫ��......\n",me);
					return 1;
				}
				
				break;
			default:
				return 1;
				break;
		}
		return 1;
	}
	else
	return 1;
}
