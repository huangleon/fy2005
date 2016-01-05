// boat.c
inherit ROOM;
void create()
{
        set("short", "�洬��");
        set("long", @LONG
���й��߻谵����ͷվ��һ���׷��ԲԵ��ϸ��ˣ�������������������վ�ڶ�
���Ĵ�ͷ�ϣ�ǿ���ĺ���䣬����ȴ��ͦ�ñ�ֱ������һ����δ����������
LONG
        );
        set("objects",([
        	AREA_TIEFLAG"npc/boater" : 1,
		]));
	set("coor/x",1420);
	set("coor/y",-410);
	set("coor/z",-30);
	set("no_fly",1);
	set("no_lu_letter",1);
	setup();
}   

void boat_run(int counter)
{
	object dest;
	object *inv;
	int i;
	
	inv=all_inventory(this_object());
	if (!present("old boater",this_object()))
	{
		for(i=0;i<sizeof(inv);i++)
			if(userp(inv[i]))
			{
				message("vision","С�����˼�ʻ���ں���������Ŀ�ĵ�Ʈ��...\n",this_object());
				call_out("boat_run",20,counter);  
				return;
			}
		remove_call_out("boat_run");
	}
			
	for (i=0;i<sizeof(inv);i++)
	    if (userp(inv[i]))
		{
	
			switch(counter){
			case 0 :	
  		  	message("vision","С������ζ���������ǰʻȥ��\n",this_object());
				break;
			case 1 :  
		        message("vision","����ˮ�������������š�\n",this_object());
				break;
		    case 2 :
		    	message("vision","�����ӳ���һ�㣬С��ת��һ������\n",this_object());
				break;
		    case 3 :
		    	message("vision", "ãã�󺣣��㲻֪��Ҫ�߶�á�\n",this_object());
				break;
		    case 4 :
		    	if (query_temp("mark/dest")=="island")
		    		message("vision", "����һ�ߴ�������һ���ڵ㣬�ڵ�Խ��Խ���㷢������һ��С����\n",this_object());
			    else
			    	message("vision", "����һ�ߴ�������һ����Ӱ����ӰԽ��Խ����\n",this_object());
	    		break;
		    case 5 :
    			message("vision","������˵���������ˣ����ǿ����´��ˡ���\n",this_object());
			    if (query_temp("mark/dest")=="island")
			    {
			    	set("exits/up",__DIR__"island");
					if (!objectp(dest=find_object(__DIR__"island")))
						dest=load_object(__DIR__"island");
					set_temp("mark/dest","mainland");
				} 
			    else
			    {
			    	set("exits/up",AREA_EASTCOAST"seaside");
	    			if (!objectp(dest=find_object(AREA_EASTCOAST"seaside")))
						dest=load_object(AREA_EASTCOAST"seaside");
					set_temp("mark/dest","island");
			    } 
			    dest->set("exits/down",AREA_CHANGCHUN"boat");
			    message("vision","һ��С������ʻ�˹�����\n",dest);
			    call_out("leave",10,dest);
			    return;
			} 
	
			call_out("boat_run",5,counter+1);
			return;
		}
}
void leave(object dest)
{
	object *inv;
	object oob;
	int i;
	if (!objectp(oob=present("old boater",this_object())) || !living(oob))
	{
		call_out("leave",20,dest);
		return;
	}
	inv=all_inventory(this_object());		
	for (i=0;i<sizeof(inv);i++)
	    if (userp(inv[i]))
		{
            message("vision","�����ӳ���һ�㣬С����ʻ�˻�ȥ��\n",dest);
            message("vision","�����ӳ���һ�㣬С����ʻ�˻�ȥ��\n",this_object());
        	delete("exits/up");
        	dest->delete("exits/down");
        	call_out("boat_run",5,0);
        	return;                    
        }
    message("vision","�����ӳ���һ�㣬С����ʻ�˻�ȥ��\n",dest);          
	delete("exits/up");
	dest->delete("exits/down");
        
    return;
}
